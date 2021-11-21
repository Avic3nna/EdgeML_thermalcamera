import zipfile

import numpy as np
import pandas as pd
import os
from utils.__RepoPath__ import repo_path
import time

"Script parameters"
label_dir = os.path.join(repo_path, "data", "labelled_data")


"Actual script"

df_list = []

# Read in the dataframes into a list
for file in os.listdir(label_dir):
    try:
        df = pd.read_json(os.path.join(label_dir, file), orient="frame")
        df_list.append(df)
    except:
        print(f"Dataframe import from file {file} was not possible. Please check the file!")

# Concatenate the dataframes from the list
df = pd.concat(df_list)

# Write out the whole data into one complete file
df.to_json(os.path.join(label_dir, "whole_data_"+str(int(time.time()))+".json"))



print("Dataset was created succesfully.")


