"""
Experimenting with Document Distance Algorithm | only for understanding, not for implementation
Dated: 22/02/2019
"""

import math


def inner_product(d1, d2):
    """
    Inner product between two vectors, where vectors
    are represented as dictionaries of (word,freq) pairs.

    Example: inner_product({"and":3,"of":2,"the":5},
                           {"and":4,"in":1,"of":1,"this":2}) = 14.0
    """
    similiarity = 0.0
    for key in d1:
        if key in d2:
            similiarity += d1[key] * d2[key]
    return similiarity


def vector_angle(d1, d2):
    """
    The input is a list of (word,freq) pairs
    Returns the angle between these two vectors.
    """
    numerator = inner_product(d1, d2)
    denominator = math.sqrt(inner_product(d1, d1) * inner_product(d2, d2))
    return math.acos(numerator/denominator)


if __name__ == "__main__":
    # input dictionaries containing frequency of corresponding words (word is used as key and frequency as value)
    dic1 = {"the": 1, "wow": 2}
    dic2 = {"the": 1, "wow": 2}

    similarity = inner_product(dic1, dic2)
    distance = vector_angle(dic1, dic2)
    print("Similarity: " + str(similarity) + "\n"
          "Distance: %0.6f (radians)" % distance)

