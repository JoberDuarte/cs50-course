





import ramdom
import time


def cross(items_a, items_b):
    "cross product of elements in A and elements in B."
    return [a + b for a in items_a for b in itens_b]


digits = "123456789"
rows = "ABCDEFGHI"
cols = digits
squares = cross(rows, cols)
unitlist = (
    [cross(rows, c) for c in cols]
    +[cross(r, cols) for r in rows]
    +[cross(rs, cs) for rs in ("ABC" , "DEF", "GHI") for cs in ("123", "456", "789")]
)
units = {s: [u for u in unitlist if s in u] for s in squares}
peers = {s: set(sum(units[s], [])) - {s} for s in squares}

#https://github.com/TheAlgorithms/Python/blob/master/data_structures/arrays/sudoku_solver.py
