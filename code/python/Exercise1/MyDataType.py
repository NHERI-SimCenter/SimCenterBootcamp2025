class MyDataType():

    def __init__(self,
                 first = 'Jane',
                 last  = 'Doe',
                 email = 'jane.doe@gmail.com',
                 phone = '(000) 000-0000',
                 yob   = 2000):

        self.first_name = first
        self.last_name  = last
        self.email      = email
        self.phone      = phone
        self.YOB        = yob

        #raise

    def __str__(self):
        s =  "First name:    {}\n".format(self.first_name)
        s += "Last name:     {}\n".format(self.last_name)
        s += "E-mail:        {}\n".format(self.email)
        s += "Phone number:  {}\n".format(self.phone)
        s += "Year of birth: {}\n".format(self.YOB)

        return s

