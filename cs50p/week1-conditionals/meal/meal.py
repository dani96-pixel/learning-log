"""
Meal Time

Suppose that you’re in a country where it’s customary to eat breakfast between
7:00 and 8:00, lunch between 12:00 and 13:00, and dinner between 18:00 and 19:00.
Wouldn’t it be nice if you had a program that could tell you what to eat when?

This program prompts the user for a time and outputs whether it’s breakfast time,
lunch time, or dinner time. If it’s not time for a meal, it outputs nothing at all.

Assumptions:
- User input is formatted in 24-hour time as #:## or ##:##
- Each meal’s time range is inclusive.
  For instance, 7:00, 7:01, 7:59, or 8:00 is breakfast time.

The program uses:
- main(): prompts user and prints the meal time
- convert(time): converts time str in 24-hour format to corresponding hours as float.
  Example: "7:30" -> 7.5
"""


def main() -> None:
    time = input("What time is it? ")
    formatted_time = convert(time)
    if 7 <= formatted_time <= 8:
        print("breakfast time")
    elif 12 <= formatted_time <= 13:
        print("lunch time")
    elif 18 <= formatted_time <= 19:
        print("dinner time")


def convert(user_time: str) -> float:
    user_time = user_time.lower().strip()
    time = user_time
    time = (
        time
        .replace("a.m.", "")
        .replace("p.m.", "")
        .strip()
        .split(":")
    )
    hour = int(time[0])
    if user_time.endswith("p.m.") and hour != 12:
        hour += 12
    minute = (float(time[1]) / 60)
    time = hour + minute
    return time


if __name__ == "__main__":
    main()
