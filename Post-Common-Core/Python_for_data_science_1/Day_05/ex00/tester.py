from statistics import ft_statistics


def main():
    try:
        ft_statistics(1, 42, 360, 11, 64, toto="mean",
                      tata="median", titi="quartile")

        print("\n\n", '-' * 30, "\n\n")

        ft_statistics(5, 75, 450, 18, 597, 27474, 48575,
                      hello="var", world="std")

        print("\n\n", '-' * 30, "\n\n")

        ft_statistics(toto="mean", tutu="median", titi="quartile")

        print("\n\n", '-' * 30, "\n\n")

        ft_statistics(5, 75, 450, 18, 597, 27474, 48575,
                      hello="heheh", world="kdekem")

    except Exception as e:
        print(f"{type(e).__name__}: {e}")


if __name__ == '__main__':
    main()
