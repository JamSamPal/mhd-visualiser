import numpy as np
import matplotlib.pyplot as plt
import glob
import time

# Get sorted list of output files
files = sorted(glob.glob("output/data_*.dat"), key=lambda x: int(x.split('_')[1].split('.')[0]))

fig, ax = plt.subplots()
line, = ax.plot([], [], lw=2)
ax.set_xlim(0, 1)
ax.set_ylim(-2, 2)
ax.set_xlabel('x')
ax.set_ylabel('By')
ax.set_title('Alfvén wave evolution w/ periodic BC')

def init():
    line.set_data([], [])
    return line,

def update(frame):
    data = np.loadtxt(files[frame])
    x = data[:, 0]
    # The magnetic field in the y direction should exhibit wave like oscillations if the model is correct
    By = data[:,6]
    line.set_data(x, By)
    ax.set_title(f"Alfvén wave at step {frame * 100}")  # Adjust if output_interval changes
    return line,

from matplotlib.animation import FuncAnimation
ani = FuncAnimation(fig, update, frames=len(files), init_func=init, blit=True, interval=100)

plt.show()
