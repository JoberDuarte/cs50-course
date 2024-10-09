import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Get stocks and shares
    stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = :user_id GROUP BY symbol HAVING total_shares > 0",
                        user_id=session["user_id"])

    # Get cash
    cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"])[0]["cash"]

    # Variables
    total_values = cash


    # Iterate over stocks and add price and total value
    for stock in stocks:
        quote = lookup(stock["symbol"])
        stock["name"] = quote["name"]
        stock["price"] = quote["price"]
        stock["value"] = stock["price"] * stock["total_shares"]
        total_values += stock["value"]


        # Format usd
        stock["price"] = usd(stock["price"])
        stock["value"] = usd(stock["value"])


    cash = usd(cash)
    total_values = usd(total_values)



    return render_template("index.html", stocks=stocks, cash=cash, total_values=total_values)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        if not symbol:
            return apology("Must provide a symbol")
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("Must provide a positive integer number of shares")

        quote = lookup(symbol)
        if quote is None:
            return apology("symbol not found")

        price = quote["price"]
        name = quote["name"]
        total_shares_cost = int(shares) * price
        cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"])[0]["cash"]

        if cash < total_shares_cost:
            return apology("not enough cash")

        #update users table
        db.execute("UPDATE users SET cash = cash - :total_shares_cost WHERE id = :user_id", total_shares_cost=total_shares_cost, user_id=session["user_id"])

        #insert purchase on transaction table
        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price) VALUES(:user_id, :symbol, :name, :shares, :price)",
                   user_id=session["user_id"], symbol=symbol, name=name, shares=shares, price=price)

        flash(f"Bought {shares} shares of {name}({symbol}) for {usd(total_shares_cost)}!")
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        quote = lookup(symbol)
        if not quote:
            return apology("Simbol not found", 400)
        return render_template("quote.html", quote=quote)
    else:
        return render_template("quote.html")




@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":

          # Ensure username was submitted
        if not request.form.get("register_username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("register_password"):
            return apology("must provide password", 403)

        # Ensure confirm_password was submitted
        elif not request.form.get("confirm_password"):
            return apology("must confirm password", 403)

       # Check if register_password == confirm_password
        elif not request.form.get("register_password") == request.form.get("confirm_password"):
            return apology("passwrords are diferent", 400)

               # Check if register_password == confirm_password
        elif request.form.get("register_password") == request.form.get("confirm_password"):
            password_hash = generate_password_hash(request.form.get("register_password"))
            username = request.form.get("register_username")
            balance = 10000.00

            try:
                values = (username, password_hash, balance)
                db.execute("INSERT INTO users (username, hash, cash) VALUES (?, ?, ?)", *values)
                return render_template("register.html")

            except Exception as e:
                print(e)
                return apology("An error occurred")

    else:
        return render_template("register.html")




@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # Get stocks and shares
    stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = :user_id GROUP BY symbol HAVING total_shares > 0",
                        user_id=session["user_id"])

    for stock in stocks:
        quote = lookup(symbol)
        stock["name"] = quote["name"]


    #submit form
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        if not symbol:
            return apology("Must provide a symbol")
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("Must provide a positive integer number of shares")
        else:
            shares = int(shares)

        for stock in stocks:
            if stock["symbol"] == symbol:
                if stock["total_shares"] < shares:
                    flash(f"You have only {shares} shares({symbol})!")
                    return apology("not enough shares")
                else:
                    #get quote
                    quote = lookup(symbol)
                    if quote is None:
                        return apology("Symbol not found")
                    name = quote["name"]
                    price = quote["price"]
                    total_sale = shares * price

                        #update users table
                    db.execute("UPDATE users SET cash = cash + :total_sale WHERE id = :user_id", total_sale=total_sale, user_id=session["user_id"])

                    #insert purchase on transaction table
                    db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price) VALUES(:user_id, :symbol, :name, :shares, :price)",
                            user_id=session["user_id"], symbol=symbol, name=name, shares=shares, price=price)

                    flash(f"sold {shares} shares of {name}({symbol}) for {usd(total_sale)}!")
                    return redirect("/")
        return apology("Symbol not found")

    else:
        return render_template("sell.html", stocks=stocks)
