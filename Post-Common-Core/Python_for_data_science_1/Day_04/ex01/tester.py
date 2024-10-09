from S1E7 import Baratheon

Robert = Baratheon("Robert")
print(Robert.family_name)
print(Robert.__str__)
print(Robert.__repr__)
print(Robert)
Bob = Baratheon.create_baratheon("Bob", True)
print(Bob)