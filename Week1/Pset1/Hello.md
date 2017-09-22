## [Specification](http://docs.cs50.net/problems/hello/hello.html#specification)

Shall we have you write your first program? Inside of your **pset1** folder, create a new folder called **hello**. Then create a new file and immediately save it as **hello.c** inside of your **hello** folder (which should be inside of your **pset1** folder). Be sure to name the file just as we have, in all lowercase; files' and folders' names in Linux are "case-sensitive." Proceed to write your first program by typing precisely these lines into the file:

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

Notice how CS50 IDE adds "syntax highlighting" (i.e., color) as you type, though CS50 IDE’s choice of colors might differ from this problem set’s. Those colors aren’t actually saved inside of the file itself; they’re just added by CS50 IDE to make certain syntax stand out. Had you not saved the file as `hello.c` from the start, CS50 IDE wouldn’t know (per the filename’s extension) that you’re writing C code, in which case those colors would be absent.

Do be sure that you type this program just right, else you’re about to experience your first bug! In particular, capitalization matters, so don’t accidentally capitalize words (unless they’re between those two quotes). And don’t overlook that one semicolon. C is quite nitpicky!

When done typing, select **File > Save** (or hit command- or control-s), but don’t quit. Recall that the red dot atop the tab should then disappear. Click anywhere in the terminal window beneath your code, and be sure that you’re inside of `~/workspace/pset1/hello/`. (Remember how? If not, type `cd` and then Enter, followed by `cd pset1/hello/` and then Enter.) Your prompt should be:

```bash
~/workspace/pset1/hello/ $
```

Let’s confirm that `hello.c` is indeed where it should be. Type

```bash
ls
```

followed by Enter, and you should see `hello.c`? If not, no worries; you probably just missed a small step. Best to restart these past several steps or ask for help!

Assuming you indeed see `hello.c`, let’s try to compile! Cross your fingers and then type

```bash
make hello
```

at the prompt, followed by Enter. (Well, maybe don’t cross your fingers whilst typing.) To be clear, type only `hello` here, not `hello.c`. If all that you see is another, identical prompt, that means it worked! Your source code has been translated to machine code (0s and 1s) that you can now execute. Type

```bash
./hello
```

at your prompt, followed by Enter, and you should see the below:

```
hello, world
```

And if you type

```bash
ls
```

followed by Enter, you should see a new file, `hello`, alongside `hello.c`. The first of those files, `hello`, should have an asterisk after its name that, in this context, means it’s "executable," a program that you can execute (i.e., run).

If, though, upon running `make`, you instead see some error(s), it’s time to debug! (If the terminal window’s too small to see everything, click and drag its top border upward to increase its height.) If you see an error like "expected declaration" or something just as mysterious, odds are you made a syntax error (i.e., typo) by omitting some character or adding something in the wrong place. Scour your code for any differences vis-à-vis the template above. It’s easy to miss the slightest of things when learning to program, so do compare your code against ours character by character; odds are the mistake(s) will jump out! Anytime you make changes to your own code, just remember to re-save via **File > Save** (or command- or control-s), then re-click inside of the terminal window, and then re-type

```
make hello
```

at your prompt, followed by Enter. (Just be sure that you are inside of `~/workspace/pset1/hello/` within your terminal window, as your prompt will confirm or deny.) If still seeing errors, try "prepending" `help50` to your command like this:

```
help50 make hello
```

That’ll pass the output of `make hello` to a program called `help50`, which CS50’s staff wrote. If `help50` recognizes your error message, it’ll offer some suggestions (in yellow). Just realize `help50` is new this year, so odds are it won’t recognize all error messages just yet!

Once you see no more errors, try "executing" (i.e., running) your program by typing

```
./hello
```

at your prompt, followed by Enter! Hopefully you now see whatever you told `printf` to print?

If not, reach out for help! Incidentally, if you find the terminal window too small for your tastes, know that you can open one in a bigger tab by clicking the circled plus (+) icon to the right of your `hello.c` tab.