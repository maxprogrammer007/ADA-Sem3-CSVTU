# Define an Item class with value and weight
class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight

# Comparison function to sort items by value-to-weight ratio in descending order
def get_ratio(item):
    return item.value / item.weight

# Function to calculate the maximum value in the knapsack
def fractional_knapsack(capacity, items):
    # Sort items by value-to-weight ratio in descending order
    items.sort(key=get_ratio, reverse=True)

    max_value = 0.0  # Maximum value in knapsack
    current_weight = 0  # Current weight in knapsack

    # Loop through sorted items
    for item in items:
        if current_weight + item.weight <= capacity:
            # If item fits, take it entirely
            current_weight += item.weight
            max_value += item.value
        else:
            # If item can't fit, take the fractional part
            remaining_weight = capacity - current_weight
            max_value += item.value * (remaining_weight / item.weight)
            break

    return max_value

# Define knapsack capacity and items (value, weight)
capacity = 50
items = [Item(60, 10), Item(100, 20), Item(120, 30)]

# Output the maximum value
print("Maximum value in Knapsack =", fractional_knapsack(capacity, items))
