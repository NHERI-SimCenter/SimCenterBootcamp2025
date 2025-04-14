class FamilyTree():
    """
    managing an entire family

    variables:
        self.family_tree_name
        self.members = []

    methods (required):
        __init__(self,name='unknown')
        __str__(self)
        __repr__(self)
        family_name(self)
        set_family_name(self,name)
        all_men(self)
        all_women(self)
        individuals(self,key='all')
        individual(self,name)
        add_individual(self,guy)
        tree_print(self)

    methods (added to simplify implementation of required methods):
        name_list(self,key='all')   ... like individuals() but returns names instead pf pointers
        find_eldest(self)           ... return the oldest male and the oldest female
        print_individual(self,person,level=0)       ... print information for person.
                                                        level for hirachy/indentation
        print_children(self,person,partner,level=0,exclusion=[])
                                                    ... print children shared by person and partner.
                                                        level for hirachy/indentation
    """

    # ==== overloading default methods ========

    def __init__(self, name='unknown'):
        self.family_tree_name = name
        self.members = []

    def __str__(self):
        s = "Family Tree Name: {}\n".format(self.family_tree_name)
        s += "-----------------------------------------\n"
        cnt = 0
        for person in self.members:
            cnt += 1
            s += "  {}: {}\n".format(cnt, person.full_name())
        return s

    def __repr__(self):
        return "{}(name='{}')".format(self.__class__.__name__, self.family_tree_name)

    # ==== interface methods (required by problem statement) ========

    def family_name(self):
        return self.family_tree_name

    def set_family_name(self, name):
        self.family_tree_name = name

    def all_men(self):
        pass

    def all_women(self):
        pass

    def individuals(self, key='all'):
        if key not in ['all', 'male', 'female']:
            raise TypeError
        pass

    def individual(self, name):
        ans = []
        pass
        return tuple(ans)

    def add_individual(self, guy):
        pass

    def tree_print(self):
        start = self.find_eldest()

        tree = "\nFamily Tree Name: {}\n".format(self.family_tree_name)
        tree += "-----------------------------------------"
        print(tree)

	% YOUR CODE BELOW

    # ==== internal use methods ========

    def name_list(self, key='all'):
        ans = []
        return ans

    def find_eldest(self):
        eldest = {'male': [], 'female': []}
        return eldest

    def print_individual(self, person):
	pass

    def print_children(self, person, partner, level=0, exclusion=[]):
        pass
