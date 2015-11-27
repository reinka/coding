import argparse

# This is a module that provides a bunch of simple methods that make
# accessing the filesystem simpler.
from utils import charting, log

# Python logging allows us to log formatted log messages at different
# log levels.
import logging

# numpy is just used for some simple array helpers
import numpy

# need to generate pseudo random numbers
import random


def generate_die_roll_sum_distribution(number_of_rolls, number_of_dice):
    values = []

    die_or_dice = "Die"
    if number_of_dice > 1: die_or_dice = "Dice"

    logging.info("Rolling " + str(number_of_dice) + " " + die_or_dice + " " + str(number_of_rolls) + " times");

    # execute number_of_rolls rolls of number_of_dice dice and accumulate the sum of the values
    for i in range(0, number_of_rolls):
        sum = 0
        for d in range(0, number_of_dice):
            sum += random.randint(1,6)

        values.extend([sum])

    # plot the output
    charting.plot_distribution("dice_rolls.png",
                               "Roll Distribution - " + str(number_of_dice) + " " + die_or_dice + ", " + str(number_of_rolls) + " rolls",
                               "Sum of Values",
                               bucket_size=1,
                               data=values,
                               show_bucket_values=True,
                               color='#59799e',
                               normalize=True)

generate_die_roll_sum_distribution(3,1)