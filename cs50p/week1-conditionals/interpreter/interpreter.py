"""
interpreter.py

Prompts the user for an arithmetic expression in the format:
x y z

where:
- x is an integer
- y is +, -, *, or /
- z is an integer

Calculates the expression and outputs the result as a
floating-point value formatted to one decimal place.

Examples:
    Input: 1 + 1
    Output: 2.0

    Input: 10 / 4
    Output: 2.5

Assume that the user will always enter the expression
with one space between x and y, and one space between y and z.
Also assume that z will not be 0 when y is /.
"""


def main() -> None:
	user_input = input("Expression: ")
	user_input = ( 
		user_input
		.lower()
		.strip()
		.split()
	)

	x = float(user_input[0])
	y = user_input[1].strip()
	z = float(user_input[2])

	print(compute_expression(x, y, z))

#Operation controller
def compute_expression(x: float, y: str, z: float) -> str:
	if y == "+":
		result = x + z
		return f"{result:.1f}"
	elif y == "-":
		result = x - z
		return f"{result:.1f}"
	elif y == "*":
		result = x * z
		return f"{result:.1f}"
	elif y == "/":
		result = x / z
		return f"{result:.1f}"
	else:
		return "Not admitted input"


if __name__ == '__main__':
	main()
