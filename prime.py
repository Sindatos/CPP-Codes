import random

# Función para verificar si un número es primo
def es_primo(numero):
    if numero < 2:
        return False
    for i in range(2, int(numero ** 0.5) + 1):
        if numero % i == 0:
            return False
    return True

# Función para lanzar un dado (número aleatorio entre 1 y 6)
def lanzar_dado():
    return random.randint(1, 6)

# Función para jugar una ronda
def jugar_ronda():
    dado1 = lanzar_dado()
    dado2 = lanzar_dado()
    total = dado1 + dado2

    print(f"Primer lanzamiento: {dado1} y {dado2} (Total: {total})")

    # Reglas especiales
    if dado1 == dado2:
        # Dobles: lanzar 3 dados adicionales
        print("Dobles! Lanzando 3 dados adicionales...")
        for _ in range(3):
            total += lanzar_dado()
        print(f"Nuevo total después de lanzar 3 dados adicionales: {total}")
    elif total == 12:
        # Preguntar si desea lanzar un dado adicional cuando el total es 12
        opcion = input("Has sacado un total de 12! ¿Deseas lanzar un dado adicional? (s/n): ").lower()
        if opcion == 's':
            total += lanzar_dado()
            print(f"Nuevo total después de lanzar 1 dado adicional: {total}")

    return total

# Función principal del juego
def jugar():
    jugar_de_nuevo = 's'

    while jugar_de_nuevo == 's':
        total_jugador1 = 0
        total_jugador2 = 0
        empate = True

        # Jugar hasta que no haya empate
        while empate:
            print("Jugador 1 juega:")
            total_jugador1 = jugar_ronda()
            print("Jugador 2 juega:")
            total_jugador2 = jugar_ronda()

            print(f"Jugador 1 total: {total_jugador1} | Jugador 2 total: {total_jugador2}")

            # Verificar si hay empate
            if total_jugador1 != total_jugador2:
                empate = False
            else:
                print("Empate! Repitiendo la ronda...")

        # Determinar el ganador
        if es_primo(total_jugador1) and es_primo(total_jugador2):
            if total_jugador1 > total_jugador2:
                print("Jugador 1 gana con un número primo!")
            else:
                print("Jugador 2 gana con un número primo!")
        elif es_primo(total_jugador1):
            print("Jugador 1 gana con un número primo!")
        elif es_primo(total_jugador2):
            print("Jugador 2 gana con un número primo!")
        elif total_jugador1 > total_jugador2:
            print("Jugador 1 gana!")
        else:
            print("Jugador 2 gana!")

        # Preguntar si desean jugar de nuevo
        jugar_de_nuevo = input("¿Quieres jugar de nuevo? (s/n): ").lower()

# Inicia el juego directamente
print("Bienvenido a Prime Jack o 23!")
jugar()
