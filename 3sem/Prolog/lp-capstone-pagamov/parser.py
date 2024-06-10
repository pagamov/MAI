import codecs
import re

out = open('tree.ged', 'r')
res = open('db.pl', 'w')
state = 'new'
persons = {}
female = []
male = []
idPerson = ''
namePerson = ''
newPersonName = ''
sexPerson = ''
childs = []
parents = []
familyres = []
def findIdPerson(line):
    return (((line[::-1])[5:])[::-1])[2:]

for line in out:
    line = line.replace('\r', '')
    if (state == 'person' and line.find('1 SEX') >= 0):
        sexPerson = (line[6:7])
    elif (state == 'person' and line.find('1 NAME') >= 0):
        namePerson = (line[7:])[:-1]
    if ((state == 'family' or state == 'newfamily') and (line.find('1 HUSB') >= 0 or line.find('1 WIFE') >= 0)):
        parents.append((line[7:])[:-1])
        state = 'family'
    elif ((state == 'family' or state == 'newfamily') and line.find('1 CHIL') >= 0):
        childs.append((line[7:])[:-1])
        state = 'family'
    if (line.find('0 @I') >= 0 and state == 'new'):
        state = 'person'
        idPerson = findIdPerson(line)
    elif (line.find('0 @F') >= 0 or line.find('0 TRLR') >= 0):
        if (state == 'family'):
            for parent in parents:
                for child in childs:
                    if (persons[child] != '' and persons[parent] != ''):
                        familyres.append(persons[child] + '", "' + persons[parent])
            childs = []
            parents = []
        state = 'newfamily'
    if (state == 'person' and idPerson != '' and namePerson != '' and sexPerson != ''):
        newPersonName = namePerson.replace(' //', '')
        namePerson = newPersonName.replace('/', '')
        persons[idPerson[:-1]] = namePerson
        if (sexPerson == 'M' and namePerson != ''):
            male.append(str(namePerson))
        elif (sexPerson == 'F' and namePerson != ''):
            female.append(str(namePerson))
        idPerson = ''
        namePerson = ''
        sexPerson = ''
        state = 'new'

for i in male:
    res.write('male("' + i + '").\n')
res.write('\n')
for i in female:
    res.write('female("' + i + '").\n')
res.write('\n')
for i in familyres:
    res.write('children("' + i + '").\n')

res.close()
out.close()
