from DiamondTrap import King

# Joffrey = King("Joffrey")
# print(Joffrey.is_alive)
# Joffrey.die()
# print(Joffrey.is_alive)
# Pierre = King.create_baratheon("Pierre", True)
# print(f"Pierre = {Pierre}")
# Paul = King.create_lannister("Paul", True)
# print(f"Paul = {Paul}")

Joffrey = King("Joffrey")
print(Joffrey.__dict__)
Joffrey.set_eyes("blue")
Joffrey.set_hairs("light")
print(Joffrey.get_eyes())
print(Joffrey.get_hair())
print(Joffrey.__dict__)

# pool = Baratheon.create_baratheon_chain(4)
pool_2 = Joffrey.create_lannister_chain(2)
print(pool_2)