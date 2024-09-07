from collections import deque


def main():
    dq = deque()  # Initialize an empty deque
    running = True

    while running:
        command = input().strip()  # Read the command

        if command == '!':
            running = False
        elif command.startswith('+'):
            _, n = command.split()
            dq.appendleft(int(n))  # Add number to the front
        elif command.startswith('-'):
            _, n = command.split()
            dq.append(int(n))  # Add number to the back
        elif command == '*':
            if not dq:
                print("error")
            else:
                sum_elements = dq[0] + dq[-1]  # Calculate sum of the first and last elements
                print(sum_elements)
                if len(dq) > 1:
                    dq.pop()  # Remove last element
                    dq.popleft()  # Remove first element
                else:
                    dq.pop()  # If only one element, just remove it
        else:
            # print("Invalid command")
            pass


if __name__ == "__main__":
    main()
