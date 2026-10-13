# coke.py
"""
In a file called coke.py, implement a program that prompts 
the user to insert a coin, one at a time, each time 
informing the user of the amount due. Once the user has 
inputted at least 50 cents, output how many cents in change 
the user is owed. Assume that the user will only input 
integers, and ignore any integer that isn’t an accepted 
denomination.
"""
# Initialize needed vars
amount_due = 50


# Function to accept the correct coins
def insert_coin() -> tuple[bool, int]:
    coin = int(input("Insert Coin: "))
    if coin in (25, 10, 5):
        return True, coin
    else:
        return False, coin


# While loop to check the prize of the coke
while amount_due > 0:
    print(f"Amount Due: {amount_due}")
    accepted, coin = insert_coin()
    if accepted:
        amount_due = amount_due - coin


# Compute the change owed
print(f"Change Owed: {-amount_due}")
