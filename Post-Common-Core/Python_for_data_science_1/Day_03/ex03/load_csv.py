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
        raise FileNotFoundError("Error: file not found")
    except pd.errors.ParserError:
        raise pd.errors.ParserError("Error: bad file")
    except Exception:
        raise Exception("Error: an error occurs. End of program")
    return None
