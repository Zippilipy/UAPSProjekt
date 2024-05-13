def format_input(input_file):
    values = []
    with open(input_file, 'r') as file:
        for line in file:
            # Split the line by spaces
            parts = line.split()
            if len(parts) >= 2:
                # Extract the numerical value
                value = int(parts[1])
                # Append to the list of values
                values.append(value)
    return tuple(values)

# Example usage
input_file = "simulations/result2/pythonsimulations.txt"
formatted_values = format_input(input_file)
print(formatted_values)
