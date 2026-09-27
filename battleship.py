import random

grid = [[0 for _ in range(8)] for _ in range(8)]
gameOver = False
aircraftCounter = 6
destroyerCounter = 4
frigateCounter = 2


def printGrid(matrix):
    for row in matrix:
        print(row)


def placeShip(matrix, size, sign):
    decision = random.choice([0, 1])
    # if == 1, horizontal

    if decision == 1:
        row = random.choice([0, 1, 2, 3, 4, 5, 6, 7])
        width = 8 - size
        column = random.choice(list(range(0, width + 1)))
        counter = 0
        checked = False

        while counter < size:
            if matrix[row][column + counter] != 0:
                # print("found issue")
                checked = True
                checked = True
                break
            else:
                counter += 1

        if checked:
            placeShip(matrix, size, sign)
        else:
            # print("no issue")
            counter = 0
            while counter < size:
                matrix[row][column + counter] = sign
                counter += 1

    elif decision == 0:
        height = 8 - size
        row = random.choice(list(range(0, height + 1)))
        column = random.choice([0, 1, 2, 3, 4, 5, 6, 7])
        counter = 0
        checked = False

        while counter < size:
            if matrix[row + counter][column] != 0:
                # print("found issue")
                checked = True
                break
            else:
                counter += 1

        if checked:
            placeShip(matrix, size, sign)

        else:
            # print("no issue")
            counter = 0
            while counter < size:
                matrix[row + counter][column] = sign
                counter += 1

        print("You are done with the game")


placeShip(grid, 6, 1)
placeShip(grid, 4, 2)
placeShip(grid, 2, 3)
printGrid(grid)

# Still working on the user interface so far only shape placement has been done


def evaluateCoordinate(xValue, yValue):
    global aircraftCounter
    global destroyerCounter
    global frigateCounter

    if grid[xValue][yValue] == 1:
        grid[xValue][yValue] = 0
        aircraftCounter -= 1
        print("you hit something")
    elif grid[xValue][yValue] == 2:
        grid[xValue][yValue] = 0
        destroyerCounter -= 1
        print("you hit something")
    elif grid[xValue][yValue] == 3:
        grid[xValue][yValue] = 0
        frigateCounter -= 1
        print("you hit something")

    if frigateCounter == 0:
        print("You removed frigate")
    elif aircraftCounter == 0:
        print("You removed aircraft")
    elif destroyerCounter == 0:
        print("You removed destroyer")

    if frigateCounter == 0 and aircraftCounter == 0 and destroyerCounter == 0:
        gameOver = True


while not gameOver:
    x = int(input("Enter x coordinate: "))
    y = int(input("Enter y coordinate: "))

    evaluateCoordinate(x, y)


print("You solved the battleship")
# Still working on the user interface so far only shape placement has been done
