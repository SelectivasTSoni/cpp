#!/bin/zsh

# remove_dot_app_ext.zsh

# make executable with:
# chmod +x remove_dot.app.ext.zsh

# run with:
# ./remove_dot_app_ext.zsh

# this removes .app extension from files, leaving them without a file extension. Used to rename executables named with .app extension when compiled, e.g. <file>.app

# The .app file extensioned is inappropriate for non-app bundled executables and newer versions of macOS enforce this.



# Loop over all .app files in the current directory
# the *.app() gets expanded by zsh to a list of all files in the dir with .app extension by zsh's "globbing engine." The .N is a glob-qualifier saying "match regular files" + Nullglob which means "if no match, expand to nothing."
for file in *.app(.N); do
  # Get the base name without the .app extension
  base="${file%.app}"

  # Rename the file
  mv -- "$file" "$base"
done
