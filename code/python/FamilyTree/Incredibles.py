"""
This file contains three examples involving the Incredibles' family Parr
"""

from Individual import *
from AltIndividual import AltIndividual
from SmartIndividual import SmartIndividual


def IncrediblesExample1():

    dad  = Individual(first='Bob',last='Parr',gender='male',dob='1985-01-02')
    mom  = Individual(first='Helen',last='Parr',gender='female',dob='1980-03-04')
    girl = Individual(first='Violet',last='Parr',gender='female',dob='2002-05-06')
    boy  = Individual(first='Jack-Jack',last='Parr',gender='male',dob='2004-07-08')

    print(mom)
    print(dad)

    # connecting individuals

    mom.add_partner(dad)
    dad.add_partner(mom)

    mom.add_child(girl)
    mom.add_child(boy)
    dad.add_child(girl)
    dad.add_child(boy)

    print(mom)
    print(dad)


def IncrediblesExample2():

    # creating Individuals

    dad  = AltIndividual(first='Bob',last='Parr',gender='male',dob='1985-01-02')
    mom  = AltIndividual(first='Helen',last='Parr',gender='female',dob='1980-03-04')
    girl = AltIndividual(first='Violet',last='Parr',gender='female',dob='2002-05-06')
    boy  = AltIndividual(first='Jack-Jack',last='Parr',gender='male',dob='2004-07-08')

    # connecting individuals

    mom.add_partner(dad)
    dad.add_partner(mom)

    mom.add_child(girl)
    mom.add_child(boy)
    dad.add_child(girl)
    dad.add_child(boy)

    girl.add_parent(mom)
    girl.add_parent(dad)
    boy.add_parent(mom)
    boy.add_parent(dad)

    print(mom)
    print(dad)
    print(girl)
    print(boy)


def IncrediblesExample3():

    # creating Individuals

    dad  = SmartIndividual(first='Bob',last='Parr',gender='male',dob='1985-01-02')
    mom  = SmartIndividual(first='Helen',last='Parr',gender='female',dob='1980-03-04')
    girl = SmartIndividual(first='Violet',last='Parr',gender='female',dob='2002-05-06')
    boy  = SmartIndividual(first='Jack-Jack',last='Parr',gender='male',dob='2004-07-08')

    # connecting individuals

    mom.add_partner(dad)
    # dad.add_partner(mom) ... done automatically

    mom.add_child(girl)
    # girl.add_parent(mom) ... done automatically
    mom.add_child(boy)
    # boy.add_parent(mom) ... done automatically
    dad.add_child(girl)
    # girl.add_parent(dad) ... done automatically
    dad.add_child(boy)
    # boy.add_parent(dad) ... done automatically

    print(mom)
    print(dad)
    print(girl)
    print(boy)
