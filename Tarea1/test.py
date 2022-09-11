import shlex, subprocess
import numpy as np
import sys

def formatnum(n):
	if n < 10:
		return f'00{n}'
	elif n < 100:
		return f'0{n}'
	else:
		return '100' 

instances = ['100-300','100-600','100-800','200-300','200-600','200-800']
thresholds = ['0.75','0.8','0.85']
program = f'./{sys.argv[1]}'
nins = 10
for th in thresholds:
	for ins in instances:
		values = []
		for i in range(1,nins+1):
			instance = f'{ins}-{formatnum(i)}'
			command = f"{program} -i {instance} {'-th'} {th}"
			args = shlex.split(command)
			result = subprocess.run(args,capture_output=True, text=True).stdout
			val = float(result.partition('= ')[2].partition('\n')[0])
			values.append(val)
		print(f'instancia: {ins}-XXX, threshold: {th}')
		print(f'valores: {values}')
		print(f'media: {"%.3f" % np.mean(values)}')
		print(f'stdev: {"%.3f" % np.std(values)}')
		print()