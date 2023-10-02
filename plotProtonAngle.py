import numpy as np
import matplotlib.pyplot as plt

myArray = []
# Open the input file for reading
with open('hehe.csv', 'r') as file:
    # Read the file line by line
    for line in file:
        # Split the line into columns using whitespace as the delimiter
        columns = line.split()

        # Check if there are at least three columns in the line
        if len(columns) >= 3:
            # Get the first three columns
            col1 = float(columns[0])
            col2 = float(columns[1])
            col3 = float(columns[2])
            
            myArray.append([col1, col2, col3])

# Close the file when done
file.close()
newArray = np.array(myArray)

gunT = newArray[:,0]
theta = newArray[:,1]
phi = newArray[:,2]

plt.plot(theta, gunT, '.')
plt.xlabel(r'$\theta_{CM}$ [rad]')
plt.ylabel('gunT [MeV]')
plt.show()
plt.savefig('theta_gunT.pdf')
