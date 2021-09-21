class c_board:
    space = [[]]
    def __init__(self):
        self.space = [[0,1,2,3,4,5,6,7],[0,1,2,3,4,5,6,7],[0,1,2,3,4,5,6,7],[0,1,2,3,4,5,6,7],[0,1,2,3,4,5,6,7],[0,1,2,3,4,5,6,7],[0,1,2,3,4,5,6,7],[0,1,2,3,4,5,6,7]]
        for i in range (0,8):
            for j in range(0,8):
                self.space[i][j] = " "
    
    def initialize_board(self):
        for i in range(0,8):
            for j in range(0,8):
                if ((i+j)%2)==0:
                    self.space[i][j]="#"
                else:
                    self.space[i][j]="_"
        
        for i in range(0,8):
            for j in range(0,8):
                print(self.space[i][j], end = " ")
            print("\n")

    
    
board1 = c_board()

board1.initialize_board()




