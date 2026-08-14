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
    time = input("What time is it? ").strip().lower()
    formated_time = convert(time)

    # a.m / p.m format
    if time.endswith("a.m.") or time.endswith("p.m."):
        if time.endswith("a.m."):
            if 7.0 <= formated_time <= 8.0:
                print("breakfast time")
        elif time.endswith("p.m."):
            if 12 <= formated_time < 13 or formated_time == 1.0:
                print("lunch time")
            if 6 <= formated_time <= 7:
                print("dinner time")
        else:
            print("")

    # 24 hour format
    else:
        if 7.0 <= formated_time <= 8.0:
            print("breakfast time")
        elif 12.0 <= formated_time <= 13.0:
            print("lunch time")
        elif 18.0 <= formated_time <= 19.0:
            print("dinner time")
        else:
            print("")


def convert(time: str) -> float:
    time = (
        time
        .replace("a.m.", "")
        .replace("p.m.", "")
        .strip()
        .split(":")
    )
    hour = float(time[0])
    minute = (float(time[1]) / 60)
    time = hour + minute
# print(time)
    return time


if __name__ == "__main__":
    main()
