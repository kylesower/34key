import os
import re

curr_dir = os.getcwd()
keymap_file = 'keymap.c'
header_file = 'layout.h'
keymap_path = os.path.join(curr_dir, keymap_file)
outfile = os.path.join(curr_dir, header_file)

keys = {
'SLSH': '/',
'BSLS': '\\\\',
'PIPE': '|',
'QUES': '?',
'COMM': ',',
'DOT': '.',
'SCLN': ';',
'COLN': ':',
'QUOT': "'",
'DQUO': '\\"',
'UNDS': '_',
'MINUS': '-',
'PLUS': '+',
'GRV': '`',
'AMPR': '&',
'ASTR': '*',
'TILD': '~',
'DLR': '$',
'PERC': '%',
'CIRC': '^',
'EXLM': '!',
'AT': '@',
'HASH': '#',
'EQUAL': '=',
'LBRC': '[',
'RBRC': ']',
'LABK': '<',
'RABK': '>',
'LPRN': '(',
'RPRN': ')',
'LCBR': '{',
'RCBR': '}'
}


def parse_keymap(file):
	with open(file, 'r') as f:
		data = f.read().replace('\n','zxzxz')
	pattern = "keymaps\[\].*?\{.*?\};"
	keymap = re.findall(pattern, data)[0]
	comm_patt = "/\*.*?\*/"
	keymap = re.sub(comm_patt, '', keymap)
	layer_names = re.findall("\[\_(.*?)\]", keymap)
	layer_patt = "4x12\((.*?)zxzxz\)"
	layer_contents = re.findall(layer_patt, keymap)
	#print(keymap)
	#print(keymap.replace('zxzxz','\n'))#.replace('\n\nBOL','BOL'))
	#print(layer_names)
	#print(layer_contents[0].replace('zxzxz', '\n').replace(' ', ''))
	return layer_names, layer_contents

def format_layer_lines(name, data):
	space_size = 9
	new_lines = name + 'zxzxz'
	new_lines += "┌─────────┬─────────┬─────────┬─────────┬─────────┐                        ┌─────────┬─────────┬─────────┬─────────┬─────────┐zxzxz"
	for line_num, line in enumerate(data):
		line = line.replace('KC_','').replace('MOD_','')
		letters = line.split(',')[:12]
		
		for l, letter in enumerate(letters):
			letter = letter.replace('_______', '         ')
			letter = letter.replace('XXXXXXX', '         ')
			letter = letter.replace('TL_', '')
			if letter in keys.keys():
				letter = keys[letter]
			match = re.findall('\((.*)\)', letter)
			if match:
				letter = match[0].replace('_', '')
				letter = letter.replace('LALT','Alt').replace('LCTL','Ctl').replace('LGUI','GUI').replace('LSFT','Sft').replace('|','')
			if line_num not in [0,4]:
				if l not in [5, 6] and l < 12:
					new_lines += '│'
					empty_num = space_size - len(letter)
					if letter.startswith('\\'):
						letter = ' ' + letter
					new_lines += ' '*(empty_num//2) + letter + ' '*(empty_num//2) + ' '*(empty_num % 2)
				if l == 5:
					new_lines += '│                        '
			elif line_num == 4:
				if l in [4, 6]:
					if l == 4:
						new_lines += '                                        '
					new_lines += '│'
					empty_num = space_size - len(letter)
					new_lines += ' '*(empty_num//2) + letter + ' '*(empty_num//2) + ' '*(empty_num % 2)
				elif l in [5, 7]:
					new_lines += '│'
					empty_num = space_size - len(letter)
					new_lines += ' '*(empty_num//2) + letter + ' '*(empty_num//2) + ' '*(empty_num % 2)
					if l == 5:
						new_lines += '│    '
					else:
						new_lines += '│zxzxz'

		if line_num not in [0,4]:
			new_lines += '│zxzxz'
			if line_num == 3:
				new_lines += "└─────────┴─────────┴─────────┴─────────┼─────────┼─────────┐    ┌─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘zxzxz"
			else:
				new_lines += "├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤zxzxz"
		elif line_num == 4:
			new_lines += "                                        └─────────┴─────────┘    └─────────┴─────────┘"
			
	return new_lines


def convert_to_basic(uni):
	dump = ""
	for line in uni[:-1].split('","'):
		new_line = line.replace('┌─',',-').replace('┼','+').replace('┴','-').replace('─┐','-.').replace('│','|')
		new_line = new_line.replace('└─','`-').replace('─┘','-\'').replace('┬','-').replace('─','-').replace('┤','|').replace('├','|')
		if new_line.startswith('"'):
			new_line = new_line[1:]
		elif new_line.endswith('"'):
			new_line = new_line[:-1]
		dump += new_line + '\\n'
	return dump
	

def make_pretty(names, contents):
	dump = ""
	for i, layer in enumerate(contents):
		layer_lines = layer.replace(' ', '').split('zxzxz')
		layer_data = format_layer_lines(names[i], layer_lines)
		#dump += layer_data.replace('zxzxz', '\n')
		layer_data = layer_data.split('zxzxz')
		for line_num, line in enumerate(layer_data):
			dump += '"' + line + '",'
	print(dump)
	return dump


def write_header(formatted_string, outfile):
	with open(outfile, 'w+', encoding="utf-8") as f:
		num_lines = formatted_string.count(',') + 1
		f.write('#ifndef LAYOUT_PRINT_H\n#define LAYOUT_PRINT_H\n')
		f.write(f'    const int layout_length = {num_lines};\n')
		f.write(f'    char *my_layout[{num_lines}] = ')
		f.write('{')
		f.write(formatted_string[:-1])
		f.write('};\n')
		f.write('    char *basic_layout = "')
		basic = convert_to_basic(formatted_string)
		f.write(basic[:-2])
		f.write('";\n#endif')

names, contents = parse_keymap(keymap_path)

formatted_string = make_pretty(names, contents)
print(names)
for layer in contents:
	print(layer.replace('zxzxz', '\n')+'\n\n')
write_header(formatted_string, outfile)

