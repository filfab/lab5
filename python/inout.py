import sys

def get_input(*argument_formats: int|float|str, varsize=False) -> list[int|float|str]:
    """Return a list of parsed inputs."""

    argument_count = len(sys.argv) - 1
    inputs = []

    if varsize:
        argument_format = argument_formats[0]

        if argument_count == 0:
            n = int(input('Number of arguments (arguments of invalid format will be ommited): '))
            for i in range(1,n+1):
                    try:
                        inputs.append(argument_format(input(f'{argument_format.__qualname__} {i}: ')))
                    except ValueError:
                        pass
        else:
            for argumet in sys.argv[1:]:
                try:
                    inputs.append(argument_format(argumet))
                except ValueError:
                    print(f'Argument {argumet} is not of type {argument_formats[0]}')
    else:
        argument_count = len(sys.argv) - 1
        inputs = []

        if argument_count == 0:
            for argument_format in argument_formats:
                inputs.append(argument_format(input(f'Input of type {argument_format.__qualname__}: ')))
        elif argument_count == len(argument_formats):
            for i, argumet in enumerate(sys.argv[1:]):
                inputs.append(argument_formats[i](argumet))
        else:
            print(f'Incorrect number of agruments given (expected {len(argument_formats)}, got {argument_count})')
            sys.exit(-1)

    return inputs
