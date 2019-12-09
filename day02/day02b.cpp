#include <intcode.h>

#include <cstdio>
#include <vector>
#include <queue>

int main(int argc, char** argv)
{
  vh::IntcodeComputer src;
  if (!src.load(argv[1])) {
    fprintf(stderr, "Failed to load %s\n", argv[1]);
    return 1;
  }

  std::queue<int64_t> input;
  std::vector<int64_t> output;

  for (int64_t noun = 0; noun < 100; noun++) {
    for (int64_t verb = 0; verb < 100; verb++) {
      vh::IntcodeComputer prog = src;
      prog.mem[1] = noun;
      prog.mem[2] = verb;
      prog.run(input, output);
      if (prog.mem[0] == 19690720) {
        printf("noun = %lld, verb = %lld, answer = %lld\n", noun, verb, noun * 100 + verb);
        return 0;
      }
    }
  }
  return 1;
}
