import sys


def helper_read(filename):
  f = open(filename, 'r')
  i = 1
  s = {}
  for line in f:
    if i > 20:
        i = (i//10+1)*10
        s[i] = line.strip('\n')
    else:
        s[i] = line.strip('\n')
        i += 1
  f.close()
  return s


def write_words(filename):
    num_dict = helper_read(filename)
    word_dict = {}

    for i in range(1,21):
        word_dict[i] = num_dict[i]

    for i in range(21, 1000):
        if i % 100 and i < 100:
            if i % 10 and i < 100:
                word_dict[i] = num_dict[i//10*10] + num_dict[i%10]
            else:
                word_dict[i] = num_dict[i]
        else:
            if i % 100:
                word_dict[i] = num_dict[i//100] + num_dict[100] + 'and' + word_dict[i%100]
            elif i//100:
                word_dict[i] = num_dict[i//100] + num_dict[100]

    word_dict[1000] = 'onethousand'
    return word_dict


def count_letters(dict):
    sum = 0
    for key in dict.keys():
        sum += len(dict[key])

    return sum



def main():
  if len(sys.argv) != 2:
    print ('usage: ./wordcount.py {--count | --topcount} file')
    sys.exit(1)

  filename = sys.argv[1]
  print(count_letters(write_words(filename)))

if __name__ == '__main__':
  main()
