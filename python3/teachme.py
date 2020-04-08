    
for case in range(int(input())):
    master = {}
    employees, skills = input().split()
    loe = []
    for employeeIndex in range(int(employees)):
        loe.append(employeeIndex + 1)
        employeeSkills = input().split()
        skills = employeeSkills[0]
        i = 1
        while i <= int(skills):
            if employeeSkills[i] in master:
                master[employeeSkills[i]].append(employeeIndex + 1)
            else:
                master[employeeSkills[i]] = [employeeIndex + 1]
            i += 1

    unSkilledEmployees = {}
    loe = set(loe)
    count = 0
    for skill, skilledEmployees in master.items():
        skilledEmployees = set(skilledEmployees)
        difference = loe.difference(skilledEmployees)
        for unskilled in difference:
            if unskilled not in unSkilledEmployees:
                unSkilledEmployees[unskilled] = len(skilledEmployees)
                count += len(skilledEmployees)
            elif unskilled in unSkilledEmployees:
                if unSkilledEmployees[unskilled] < len(skilledEmployees):
                    count += len(skilledEmployees) - unSkilledEmployees[unskilled]
                    unSkilledEmployees[unskilled] = len(skilledEmployees)
    print('Case #%d: %d' % (case+1, count))