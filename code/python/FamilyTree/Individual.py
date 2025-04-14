"""
=======================================
Exercise 2:  Designing a Family Tree
=======================================

We want to create a series of classes to represent entries in a family tree.
Each entry 'Individual' shall provide the following methods:

| method       |input|returns| notes                                      |
|:-------------|:----|:------|:-------------------------------------------|
| `first_name` | none| string|                                            |
| `last_name`  | none| string|                                            |
| `full_name`  | none| string| as `'first last'`                          |
| `gender`     | none| string| default to `'unknown'`                     |
| `DOB`        |     | string| date of birth as string `'YYYY-MM-DD'`     |
| `children`   |     | tuple | as a list of (pointers to) child objects   |
| `partner`    |     | tuple | as a list of (pointers to) partner objects,
                               most cases empty or one, but ...           |
| `add_child`  |child object|-| adds that child to the list of children   |
| `add_partner`|another
                individual
                object|      | add that partner to partner list           |
| `__str__`    |     | string| a nice representation of this `Individual` |


**Your Task**:

1. Given the `Human` class defined below, create the `Individual` class by deriving it from
   `Human` through **inheritance** and adding **only necessary** methods, thus, minimizing your effort.

2. add some simple test that creates a small family with parents and two children.
   Use `print(mom)` (or similar) to produce nice info.

"""


from Human import *

class Individual(Human):
    """
    Representation of an Individual

    variables:
        self.the_partner = []
        self.the_children = []

    variables (inherited):
        self.firstname
        self.lastname
        self.my_gender
        self.date_of_birth

    methods:
        __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01')
        __str__(self)
        partner(self)
        children(self)
        add_partner(self, partner)
        add_child(self, child)
    """

    def __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01'):
        super().__init__(first=first,last=last,gender=gender,dob=dob)
        self.the_partner  = []
        self.the_children = []

    def __str__(self):
        s = super().__str__()
        if self.the_partner:
            for ind in self.the_partner:
                s += f"partner: {ind.full_name()}\n"
        if self.the_children:
            for ind in self.the_children:
                s += f"child: {ind.full_name()}\n"
        return s

    def gender(self):
        return self.my_gender

    def DOB(self):
        return self.date_of_birth

    def partner(self):
        return self.the_partner

    def children(self):
        return self.the_children

    def add_partner(self, partner):
        self.the_partner.append(partner)

    def add_child(self, child):
        if child not in self.the_children:
            self.the_children.append(child)
        else:
            print("{} already known".format(child.full_name()))


if __name__ == "__main__":


    # human1 = Individual()
    # human2 = Individual(first='John',last='Doe',gender='male',dob='1950-07-04')
    #
    # print(human1.full_name())
    # print(human1)
    #
    # print("---")
    #
    # print(human2.first_name())
    # print(human2.last_name())
    # print(human2.full_name())
    # print(human2)
    # print(repr(human2))

    # creating Individuals

    dad  = Individual(first='Bob',last='Parr',gender='male',dob='1985-01-02')
    mom  = Individual(first='Helen',last='Parr',gender='female',dob='1980-03-04')
    girl = Individual(first='Violet',last='Parr',gender='female',dob='2002-05-06')
    boy  = Individual(first='Jack-Jack',last='Parr',gender='male',dob='2004-07-08')

    print(mom)
    print(dad)

    print("1:", mom.first_name())
    print("2:", mom.last_name())
    print("3:", mom.full_name())
    print("4:", mom.gender())
    print("5:", mom.DOB())
    kids = mom.children()
    if kids:
        print("6:", kids)
    else:
        print("6: no kids")
    partner = mom.partner()
    if partner:
        print("7:", partner)
    else:
        print("7: no partner")

    mom.add_partner(dad)
    mom.add_child(boy)
    mom.add_child(girl)

    kids = mom.children()
    if kids:
        print("8:", [ kid.full_name() for kid in kids ] )
    partner = mom.partner()
    if partner:
        print("9:", [ x.full_name() for x in partner ] )

    dad.add_partner(mom)
    dad.add_child(girl)
    dad.add_child(girl)
    dad.add_child(boy)

    kids = dad.children()
    if kids:
        print("10:", [ kid.full_name() for kid in kids ] )
    partner = dad.partner()
    if partner:
        print("11:", [ x.full_name() for x in partner ] )
