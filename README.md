![header](./documentation/header.png)

Raider is a file listener which can do:
- colorization of file modifications using a regular expression and printing it to the stdout.
- transmission of file modifications via UDP to a data sink

I made this application because I needed a simple solution, which can spy a single file which is deleted, recreated and modified to store log output. Furthermore I needed to build this software for different target systems. If you need a more advanced solution to watch log files, I would recommend you to look at [the log file navigator](http://lnav.org/).


**Options:**
```
Usage: ./raider [options] settings
File colorization and transmitting.

Options:
  -h, --help                     Displays this help.
  -v, --version                  Displays version information.
  --hl, --highlight <arguments>  First sign e.g. @ defines the delimiter.
                                 Requires 5 delimiters to be a valid expression.
                                 Example: @color@pre@regex@post@
  --cl, --colors                 Printing a list of available colors.

Arguments:
  settings                       Requires path to settings file.

```

**Example:**
```
python app/python/file-writer.py
python app/python/udp-receiver.py
./raider ABSOLUTE_PATH_TO/settings.json --highlight @light_cyan@\\t@Everyday@@
```
