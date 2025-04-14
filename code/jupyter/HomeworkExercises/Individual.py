# **************************************************************************
# 
# class: Individual
#
# author:    Peter Mackenzie-Helnwein
# created:   pmh - 10/28/2020
# modified:  pmh - 07/28/2024
#
# **************************************************************************


from Human import *


class Individual(Human):
    """
    Modify Individual to incorporate parent information

    variables:
        self.the_partner = []
        self.the_children = []
        self.the_parents = []

    variables (inherited):
        self.firstname
        self.lastname
        self.gender
        self.date_of_birth

    methods:
        __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01')
        __str__(self)
        partner(self)
        children(self)
        add_partner(self, partner)
        add_child(self, child)
        parents(self)
        add_parent(self, parent)

    methods (inherited BUT overloaded/hidden):
        __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01')
        __str__(self)

    methods (inherited, not overloaded):
        __repr__(self)
        first_name(self)
        last_name(self)
        full_name(self)
    """

    def __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01'):
        super().__init__(first=first,last=last,gender=gender,dob=dob)
        self.the_partner = []
        self.the_children = []
        self.the_parents = []

    def __str__(self):
        s = super().__str__()
        if self.the_parents:
            s += "Parents:    {}\n".format([ parent.full_name() for parent in self.the_parents ])
        if self.the_partner:
            s += "Partner(s): {}\n".format([ partner.full_name() for partner in self.the_partner ])
        if self.the_children:
            s += "Children:    {}\n".format([ child.full_name() for child in self.the_children ])
        return s

    def partner(self):
        pass

    def parents(self):
        pass

    def children(self):
        pass

    def add_partner(self, partner):
        pass

    def add_child(self, child):
        pass

    def add_parent(self, parent):
        pass

