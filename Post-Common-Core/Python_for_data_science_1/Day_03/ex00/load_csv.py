import pandas as pd


def check_arg(file):
    '''Read the file and create a dataframe based on that file if it respect
    the format and do not contain error'''
    data = pd.read_csv(file)
    return data


def load(file):
    '''Load a Pandas DataFrame from a file and returns it'''
    try:
        data = check_arg(file)
        print(f"Loading dataset of dimensions {data.shape}")
        return (data)
    except FileNotFoundError:
        print("File not found")
    except pd.errors.ParserError:
        print("The file is not correct")
    except Exception as e:
        print(f"Une erreur s'est produite: {e}")
    return None
