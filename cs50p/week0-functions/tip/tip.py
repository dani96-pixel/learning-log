"""
(...)
Copy and paste the code above into a file, 
and complete the implementations of 
dollars_to_float and percent_to_float, 
replacing each TODO with one or more lines 
of your own code.
"""
def main():
	dollars = dollars_to_float(input("How much was the meal? "))
	percent = percent_to_float(input("What percentage would you like to tip? "))
	tip = dollars * percent
	print(f"Leave ${tip:.2f}")

def dollars_to_float(d: str) -> float:
	d = d.replace("$", "")

	d = float(d)

	return d


def percent_to_float(p: str):
	p = p.replace("%", "")

	p = float(p)

	p /= 100

	return p


main()
