def longest_unique_substring(s: str) -> int:

    if not s: return 0
    left = 0
    max_length = 0
    char_set = set()

    for right in range(len(s)):
        while s[right] in char_set:
            char_set.remove(s[right])
            left += 1
        char_set.add(s[right])
        current_length = right - left + 1
        max_length = max(max_length, current_length)
    return max_length

print(longest_unique_substring("abcbbdefa"))