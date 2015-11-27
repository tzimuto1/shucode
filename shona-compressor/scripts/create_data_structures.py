import string

stems_dic = {"b": ["b", "bh", "bv", "bw"],\
         "c": ["ch", "chw"],\
         "d": ["d", "dh", "dy", "dz", "dzv", "dzw"],\
         "f": ["f"],\
         "g": ["g", "gw"],\
         "h": ["h", "hw"],\
         "j": ["j"],\
         "k": ["k", "kw"],\
         "m": ["m", "mb", "mbw", "mh", "mv", "mw"],\
         "n": ["n'", "n", "nd", "ndw", "ng", "ngw", "nh", "nj", "nw", "ny", "nz", "nzw", "nzv"],\
         "p": ["p", "pf", "pw"],\
         "r": ["r", "rw"],\
         "s": ["s", "sh", "shw", "sv", "sw"],\
         "t": ["t", "ts", "tsw", "tsv", "tw"],\
         "v": ["v", "vh"],\
         "w": ["w"], \
         "y": ["y"], \
         "z": ["z", "zh", "zhw", "zv", "zw"]
}




def create_regex():
    regex = "(("
    for key in prefix_chars:
        regex = regex + "|".join([stem[0].upper() + stem[1:] for stem in stems_dic[key]]) + "|"
        regex = regex  + "|".join(stems_dic[key]) + "|"
    #remove the terminal "|"
    regex = regex[:-1]

    regex += ")[aeiou])|([\\t\\n\\r -~])";
    return regex

def count_shona_syllbs():
    count = 0
    for c in prefix_chars:
        count += len(stems_dic[c])
    return count * 5 * 2

def get_data_structures():
    shona_syllbs_num    = count_shona_syllbs()
    printable_char_num  = 98
    
    all_syllbs          = [None] * (shona_syllbs_num + printable_char_num)
    ranges              = [None] * printable_char_num
    
    idx                 = 0
    range_idx           = 0

    #handle the set {\t, \r,\n}
    all_syllbs[idx : idx + 3]    = ["\\t", "\\n", "\\r"]
    ranges[range_idx : range_idx + 3]  = [[idx] * 2, [idx + 1] * 2, [idx + 2] *2];
    idx                += 3
    range_idx          += 3
    
    #deal with characters before alphas
    for i in range(32, 65):
        if i == 34:
            all_syllbs[idx] = "\\" + chr(i)
        else:
            all_syllbs[idx] = chr(i)
        ranges[range_idx] = [idx, idx]
        idx += 1
        range_idx += 1
    
    #deal with alphas
    alpha_syllb_offset = shona_syllbs_num / 2 + 26 + 6#offset from Uppercase syllb to Lowercase syllb
    
    for c in string.lowercase:
        
        upper_char_start_idx = idx
        #input the characters
        all_syllbs[idx] = c.upper()
        all_syllbs[idx + alpha_syllb_offset] = c
        idx += 1

        #now deal with the syllables
        if c in prefix_chars:
            for syllb_stem in stems_dic[c]:
                lowercase_syllbs = [syllb_stem + vowel for vowel in "aeiou"]
                for syllb in lowercase_syllbs:
                    #uppercase
                    all_syllbs[idx] = syllb[0].upper() + syllb[1:]
                    #lowercase
                    all_syllbs[idx + alpha_syllb_offset] = syllb

                    idx += 1
        
        ranges[range_idx] = [upper_char_start_idx, idx - 1]
        ranges[range_idx + 26 + 6] = [upper_char_start_idx + alpha_syllb_offset, idx + alpha_syllb_offset - 1]
        range_idx += 1

    #indexes of open brace
    open_brace_syllb_idx = idx + alpha_syllb_offset
    open_brace_range_idx = range_idx + 26 + 6
    
    #deal with 91-96
    for i in range(91, 97):
        if i == 92:
            all_syllbs[idx] = "\\" + chr(i)
        else:
            all_syllbs[idx] = chr(i)
        ranges[range_idx] = [idx, idx]
        idx += 1
        range_idx += 1

    #deal with the rest of the chars (123-126)
    idx       = open_brace_syllb_idx
    range_idx = open_brace_range_idx
    for i in range(123, 127):
        all_syllbs[idx]   = chr(i)
        ranges[range_idx] = [idx]*2
        idx              += 1
        range_idx        += 1

    all_syllbs = all_syllbs[:37] + sorted(all_syllbs[37:])
    return (all_syllbs, ranges)

def write_regex():
    print "/**\n This a Shona regex that works with any type of Shona text (e.g mixture of Shona and English/Numbers)\n*/"
    print 'const char shona_regex[] = "' + REGEX + '";\n'

def write_structure_array():
    '''
    The structure is:
    struct node {
      char *symbol;//syllable
      int  code;
      int  nbits;
      int  freq;
      node *left;
      node *right;
    };
    '''
    comment = "/**\n This is a list of all the syllables that exist in the Shona language. In this case we treat all the characters starting from chr(33) to chr(126) as Shona syllables. This means that we can compress any typy of a Shona document (e.g mixture of Shona and English).\n*/"
    count = 0
    array_str = "node node_list[] = {\n"
    for syllable in ALL_SYLLABLES:
        struct = "    {{\"{0}\", {1}, {2}, {3}, NULL, NULL}},//{4}\n".format(syllable, 0, 0, 0, count)
        count += 1
        array_str += struct 
    array_str += "};\n"
    print comment
    print array_str

def write_structure_array_size():
    print "const int NODE_COUNT = " + str(len(ALL_SYLLABLES)) + ";\n"
        
def write_ranges():
    comment = "/**\n This is the list of index pairs corresponding to each of the printable characters. The range specifies the indexes over which the syllables starting with the character occur in the node_list above.\n*/"

    all_printable_chars = ["\\t", "\\n", "\\r"] + sorted(string.printable)[5:];
    ranges    = "const int printable_char_ranges[98][2] = {\n"
    count     = 0
    for irange in RANGES:
        #if irange == None:
        #    break
        c = all_printable_chars[count]
        if c == '\\':
            c = "backslash"
        irange = "    {{{0}, {1}}}, //{2} {3}\n".format(irange[0], irange[1], c, count)
        ranges += irange
        count += 1
    ranges += "};\n"
    print comment
    print ranges

    
prefix_chars = sorted(stems_dic.keys())
prefix_chars_set = set(prefix_chars)

REGEX = create_regex()

data_structures = get_data_structures()
ALL_SYLLABLES = data_structures[0]
RANGES = data_structures[1]

print "#include \"data.h\"\n\n"
write_regex()
write_structure_array()
write_structure_array_size()
write_ranges()
