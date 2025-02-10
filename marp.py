import argparse
import os
import re


def read_file(filepath):
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            return f.read()
    except FileNotFoundError:
        print(f"File {filepath} not found.")
        return "???"


def process_file(main_filename,out_filename):

    dir = os.path.dirname(main_filename)
    out_filename = dir + "/" + out_filename

    content = read_file(main_filename)
    
    # @{{inline}}{path/to/file.txt}
    inline_pattern = re.compile(r"@\{\{inline\}\}\{(.*?)\}")
    
    def inline_replacer(match):
        file_to_include = match.group(1)
        return "\n```cpp\n"+read_file(dir+"/"+file_to_include)+"\n```\n"
    
    content = inline_pattern.sub(inline_replacer, content)
    
    #  @{{inline_table}}{path/to/file.txt; path/to/file2.txt}
    table_pattern = re.compile(r"@\{\{inline_table\}\}\{(.*?)\}")
    table_pattern_hless = re.compile(r"@\{\{inline_table_hless\}\}\{(.*?)\}")

    def table_replacer(match, h_less = False):
        file_paths = match.group(1).split(';')
        file_paths = [path.strip() for path in file_paths]
        
        headers = "".join(f"<th>{path.split('/')[-1]}</th>" for path in file_paths)
        if h_less :
            headers = ""
        contents = "".join(f"<td>\n\n```cpp\n{read_file(dir+'/'+path)}\n```\n</td>" for path in file_paths)
        
        return f"<table><tr> {headers} </tr><tr>  {contents} </tr></table>"
    

    content = table_pattern.sub(table_replacer, content)

    content = table_pattern_hless.sub(lambda x:table_replacer(x,True), content)

    with open(out_filename, 'w', encoding='utf-8') as f:
        f.write(content)
    
    print(f"File {out_filename} updated.")



if __name__ == "__main__":

    parser = argparse.ArgumentParser(prog='prep_tools.py')
    parser.add_argument("-i", "--input", help="input .md file" , type=str, required=True)

    args = parser.parse_args()
    process_file(args.input, "lecture.md")