# auditor.py
"""
Universal Unit & Currency Auditor

Imagine you work as a data steward for a global logistics company. Every day,
thousands of transaction records arrive in messy, inconsistent formats.
Wouldn't it be nice if a program could audit each one for you?

This program prompts the user for a transaction record and prints whether it's
accepted or rejected, based on rules for its category, unit, and value.

Input format:
- '[Value] [Unit/Currency] [Category]', e.g. "1500 $ finance" or "45.5 kg inventory"

Assumptions:
- Value is always a valid number.
- Unit and Category are matched case-insensitively.

Rules:
- finance: unit must be $ or €.
  value > 1000.0        -> "Requires Manager Approval"
  value <= 1000.0        -> "Transaction Cleared"
- inventory: unit must be kg or lb.
  kg in [0, 500]          -> "Inventory Verified"
  lb in [0, 1100]         -> "Inventory Verified"
  otherwise               -> "Weight Limit Exceeded"
- anything else (unrecognized category, or valid category with wrong unit)
                          -> "Invalid Record Type"

The program uses:
- main(): prompts the user and prints the audit result
- parse_record(record): cleans a raw input string into (value, unit, category)
- audit_record(value, unit, category): applies the rules above and returns the result
- is_within_range(value, min_val, max_val): returns True if min_val <= value <= max_val
"""
from typing import Tuple


def main() -> None:
    """
    Prompt the user for a transaction record in the format
    '[Value] [Unit/Currency] [Category]', audit it against the
    finance and inventory rules below, and print the result:
    Transaction Cleared, Requires Manager Approval, Inventory
    Verified, Weight Limit Exceeded, or Invalid Record Type.
    """
    user_prompt = input("Record: ")
    value, unit, category = parse_record(user_prompt)
    result = audit_record(value, unit, category)
    print(result)


def parse_record(record: str) -> tuple[float, str, str]:
    """
    Clean and split a raw record string into (value, unit, category).
    """
    record = (
        record
        .lower()
        .split()
    )
    value = float(record[0])
    unit = record[1]
    category = record[2]

    return value, unit, category


def audit_record(value: float, unit: str, category: str) -> str:
    """
    Apply the finance/inventory rules and return the audit result.
    """
    match category:
        case 'finance':
            if unit != '$' and unit != '€':
                return "Invalid Record Type"

            bool_flag = is_within_range(value, 0, 1000)
            if bool_flag:
                return "Transaction Cleared"
            else:
                return "Requires Manager Approval"

        case 'inventory':
            if unit == 'kg':
                bool_flag_kg = is_within_range(value, 0, 500)
                if bool_flag_kg:
                    return "Inventory Verified"
                else:
                    return "Weight Limit Exceeded"
            elif unit == 'lb':
                bool_flag_lb = is_within_range(value, 0, 1100)
                if bool_flag_lb:
                    return "Inventory Verified"
                else:
                    return "Weight Limit Exceeded"
            else:
                return "Invalid Record Type"

        case _:
            return "Invalid Record Type"


def is_within_range(value: float, min_val: float, max_val: float) -> bool:
    """
    Return True if min_val <= value <= max_val, else False.
    """
    if min_val <= value <= max_val:
        return True
    else:
        return False


if __name__ == "__main__":
    main()
