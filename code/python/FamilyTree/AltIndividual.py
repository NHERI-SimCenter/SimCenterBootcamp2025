"""
3. Create a new class AltIndividual from Individual that adds the ability to store information on parents.

   * What member variables need to be added?
   * What methods need to be added?
   * create a simple test and demonstrate the new feature

"""

from Individual import *

class AltIndividual(Individual):
    """
    Modify Individual to incorporate parent information

    variables:
        self.the_parents = []

    variables (inherited):
        self.firstname
        self.lastname
        self.gender
        self.date_of_birth
        self.the_partner = []
        self.the_children = []

    methods:
        __str__(self)
        parents(self)
        add_parent(self, parent)
    """

    def __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01'):
        super().__init__(first=first, last=last, gender=gender, dob=dob)

    def parents(self):
        pass

    def add_parent(self, parent):
        pass
