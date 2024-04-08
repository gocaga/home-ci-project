import os

from invoke import Collection, task

# Constants
CWD = "/mnt/c/Users/gocag/STM32CubeIDE/workspace_1.15.0/MCU1-Course/MCU1/001-Tool-Setup-semihosting/Debug/"

PATH = os.environ

@task
def build(context):
    """Build the project"""
    with context.cd(CWD):
        env = {"PATH":""}
        context.run("make -j4 all", env=env)
        #print (os.environ)
        #print (os.O_PATH)
        #print (CWD)
        #context.run(pwd)


