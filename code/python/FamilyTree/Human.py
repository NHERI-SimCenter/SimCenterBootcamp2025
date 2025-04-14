class Human():
    """
    Representation of a Human

    variables:
        self.firstname
        self.lastname
        self.my_gender
        self.date_of_birth

    methods:
        __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01')
        __str__(self)
        __repr__(self)
        first_name(self)    ... returns the first name as a string
        last_name(self)     ... returns the last name as a string
        full_name(self)
    """

    def __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01'):
        self.firstname = first
        self.lastname  = last
        self.my_gender = gender
        self.date_of_birth = dob

    def __str__(self):
        s =  "First name:    {}\n".format(self.firstname)
        s += "Last name:     {}\n".format(self.lastname)
        if self.my_gender == 'unknown':
            s += "Gender:        undisclosed\n"
        else:
            s += "Gender:        {}\n".format(self.my_gender)
        s += "date of birth: {}\n".format(self.date_of_birth)
        return s

    def __repr__(self):
        template="{}(first='{}',last='{}',gender='{}',dob='{}')"
        s = template.format(self.__class__.__name__,
                            self.firstname,
                            self.lastname,
                            self.my_gender,
                            self.date_of_birth)
        return s

    def first_name(self):
        return self.firstname

    def last_name(self):
        return self.lastname

    def full_name(self):
        #return "{} {}".format(self.firstname, self.lastname)
        return "{} {}".format(self.first_name(), self.last_name())


if __name__ == "__main__":

    human1 = Human()
    human2 = Human(first='John',last='Doe',gender='male',dob='1950-07-04')

    print(human1.full_name())
    print(human1)

    print("---")

    print(human2.first_name())
    print(human2.last_name())
    print(human2.full_name())
    print(human2)
    print(repr(human2))
