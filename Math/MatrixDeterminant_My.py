import numpy as np

a = np.array(  [[1,-2,4],[-5,2,0],[1,0,3]]  )
b = np.array( [[1,0,0],[0,1,0],[0,0,1]] )
c = np.array( [[2,-1,3,0],[-3,1,0,4],[-2,1,4,1],[-1,3,0,-2]]   )

def determinant(mat):
	n = mat.shape[0]
	new_n = n - 1

	if n == 1:
		return mat[0,0]

	det = 0
	for i in range(n):

		new_mat = np.hstack(  ( mat[1:, :i] , mat[1:, i+1:] )  )

		if i%2 == 0:
			det += mat[0,i] * determinant(new_mat)
		else:
			det -= mat[0,i] * determinant(new_mat)

	return det


print(c)
print( 'Det = ' , determinant(c) )
