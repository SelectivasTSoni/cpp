#!/bin/zsh

#!/bin/zsh

# Usage:
#   ./strip_app_ext.zsh              # non-recursive, current directory
#   ./strip_app_ext.zsh -r           # recursive, current directory
#   ./strip_app_ext.zsh --dry-run    # preview changes
#   ./strip_app_ext.zsh -r --dry-run ./some/dir

# Default values
TARGET_DIR="."
DRY_RUN=false
RECURSE=false

# Parse arguments
for arg in "$@"; do
  case "$arg" in
    -r)
      RECURSE=true
      ;;
    --dry-run)
      DRY_RUN=true
      ;;
    *)
      TARGET_DIR="$arg"
      ;;
  esac
done

# Build the find command
if [[ "$RECURSE" == true ]]; then
  FIND_CMD=(find "$TARGET_DIR" -type f -name "*.app")
else
  FIND_CMD=(find "$TARGET_DIR" -maxdepth 1 -type f -name "*.app")
fi

# Run find and process matches
"${FIND_CMD[@]}" | while IFS= read -r file; do
  new_name="${file%.app}"

  if [[ "$file" == "$new_name" ]]; then
    continue  # Skip if no change would occur
  fi

  if [[ "$DRY_RUN" == true ]]; then
    echo "[Dry run] Would rename: $file -> $new_name"
  else
    mv -- "$file" "$new_name"
    echo "Renamed: $file -> $new_name"
  fi
done
