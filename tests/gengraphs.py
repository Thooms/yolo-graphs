import random

if __name__ == '__main__':
    V, E = 10, 50
    path = 'directed_{}_{}.yolo'.format(V, E)
    title = 'YOLO_{}_{}'.format(V, E)
    
    with open(path, 'w') as f:
        f.write(title + '\n')
        
        f.write(str(V) + '\n')
        for _ in xrange(V):
            rname = ''.join(map(chr, random.sample(xrange(65, 91), 5))) + '\n'
            f.write(rname)

        f.write(str(E) + '\n')
        for _ in xrange(E):
            start = random.randint(0, V-1)
            end = random.randint(0, V-1)
            typ = random.choice(['Road', 'Train', 'Plane'])
            dist = random.uniform(100.0, 3000.0)

            f.write('{} {} {} {}\n'.format(start, end, typ, dist))

    
