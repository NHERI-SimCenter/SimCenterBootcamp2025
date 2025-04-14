"""
This file contains three examples involving the extended Duck family
"""

from AltIndividual import AltIndividual as Individual

def DisneyExample():

    donald       = Individual(first='Donald',last='Duck',gender='male',dob='1937-01-01')
    daisy        = Individual(first='Daisy',last='Duck',gender='female',dob='1938-01-01')
    gladstone    = Individual(first='Gladstone',last='Gander',gender='male',dob='1937-01-01')
    scrooge      = Individual(first='Scrooge',last='McDuck',gender='male',dob='1900-01-01')
    grandma      = Individual(first='Grandma',last='Duck',gender='female',dob='1900-01-21')
    huey         = Individual(first='Huey',last='Duck',gender='male',dob='1948-11-01')
    dewey        = Individual(first='Dewey',last='Duck',gender='male',dob='1949-11-01')
    louie        = Individual(first='Louie',last='Duck',gender='male',dob='1950-11-01')
    april        = Individual(first='April',last='Duck',gender='female',dob='1948-01-01')
    may          = Individual(first='May',last='Duck',gender='female',dob='1949-01-01')
    june         = Individual(first='June',last='Duck',gender='female',dob='1950-01-01')
    quackmore    = Individual(first='Quackmore',last='Duck',gender='male',dob='1935-01-01')
    greatgrandma = Individual(first='GreatGrandma',last='Duck',gender='female',dob='1878-01-21')
    newey        = Individual(first='Newey',last='Duck',gender='male',dob='1956-11-01')

    grandma.add_child(donald)
    grandma.add_child(gladstone)
    grandma.add_child(quackmore)
    quackmore.add_child(huey)
    quackmore.add_child(dewey)
    quackmore.add_child(louie)
    donald.add_partner(daisy)
    grandma.add_parent(greatgrandma)
    scrooge.add_parent(greatgrandma)
    april.add_parent(daisy)
    may.add_parent(daisy)
    daisy.add_child(june)
    newey.add_parent(daisy)
    newey.add_parent(donald)

    family = [donald,daisy,gladstone,scrooge,grandma,huey,
                   dewey,louie,april,may,june,quackmore,greatgrandma,newey]

    for person in family:
        print(person)
