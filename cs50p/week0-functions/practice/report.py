"""
Project: Global Expense Reporter

The Problem:
You are working for a travel agency that receives sloppy data from users. 
You need to create a program that takes a traveler's name, a raw string 
containing a destination and a budget, and the number of days for the trip. 
The program must then "clean" this data and provide a formatted financial report.

Requirements:
- Prompt the user for: Full Name, Trip Info (destination ; total_cost), and Days.
- Implement the following custom functions:
    * clean_name(s): Strips whitespace and returns Title Case [3, 4].
    * parse_trip(s): Splits string at ';' and returns Title Case destination 
      and float cost [5, 6].
    * calculate_daily(total, days): Calculates and returns cost per day.
- Output a final report using a single f-string with :,.2f formatting for 
  thousands separators and two decimal places [7, 8].

Logic & Structure:
- Use .strip(), .title(), and .split(";") for string manipulation [3-5].
- Ensure type conversion to float for costs and int for days [6, 9].
- Include a main() function and call it at the bottom of the file [10, 11].

Demo:
Name:   jAnE dOe  
Trip Info: mAdRiD ; 15400.9
Days: 5

Hello, Jane Doe!
Your trip to Madrid will cost $15,400.90 in total.
That averages to $3,080.18 per day.
"""
# Import the tool to type correctly
from typing import Tuple


# Define main function
def main() -> None:
    # Ask user for data
    full_name = input("Name: ")
    trip_info = input("Trip Info: ")
    days = int(input("Days: ").strip())

    # Call aux functions to clean the data
    full_name = clean_name(full_name)
    destination, total_cost = parse_trip(trip_info)
    avg_cost_day = calculate_daily(total_cost, days)

    # Create the report
    print(f"\nHello, {full_name}!\n"
          f"Your trip to {destination} will cost ${total_cost:,.2f} in total.\n"
          f"That averages to ${avg_cost_day:,.2f} per day.\n"
          )


# Define the custom functions
def clean_name(s: str) -> str:
    """
    Strips whitespace and returns Title Case
    """
    s = (
        s
        .strip()
        .title()
    )
    return s


def parse_trip(s: str) -> Tuple[str, float]:
    """
    Splits string at ';' and returns Title Case destination and float cost.
    """
    s = (
        s
        .title()
        .split(";")
    )
    destination = s[0].strip()
    cost = float(s[1])
    return destination, cost


def calculate_daily(total: float, days: int) -> float:
    """
    Calculates and returns cost per day.
    """
    daily = total / days
    return daily


# Call main function
if __name__ == "__main__":
    main()
