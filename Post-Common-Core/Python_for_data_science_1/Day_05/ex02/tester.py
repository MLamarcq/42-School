from callLimit import callLimit


def main():
    try:
        @callLimit(3)
        def f():
            print("f()")

        @callLimit(1)
        def g():
            print("g()")

        for i in range(3):
            f()
            g()
    except Exception as e:
        print(f"{type(e).__name__}: {e}")


if __name__ == '__main__':
    main()
