from new_student import Student


def main():
    try:
        student = Student("Edward", "agle")
        print(student)

        student = Student(name="Edward", surname="agle", id="toto")
        print(student)
    except Exception as e:
        print(f"{type(e).__name__}: {e}")


if __name__ == '__main__':
    main()
