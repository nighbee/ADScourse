from collections import deque


def main():
    n = int(input())  # Read the number of test cases

    for _ in range(n):
        x = int(input())  # Read the size of the sequence
        size = x
        dq = deque()  # Initialize an empty deque
        dq.appendleft(x)

        x -= 1
        while x != 0:
            dq.appendleft(x)
            cnt = 0

            # Rotate the deque by moving the last element to the front 'x' times
            while cnt != x:
                dq.appendleft(dq.pop())
                cnt += 1

            x -= 1

        # Print the elements in the deque
        for _ in range(size):
            print(dq.popleft(), end=" ")
        print()  # Print newline after each test case


if __name__ == "__main__":
    main()
