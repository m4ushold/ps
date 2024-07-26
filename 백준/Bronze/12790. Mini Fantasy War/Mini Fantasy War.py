def calculate_battle_power(*stats):
    final_hp = max(1, stats[0] + stats[4])
    final_mp = max(1, stats[1] + stats[5])
    final_attack = max(0, stats[2] + stats[6])
    final_defense = stats[3] + stats[7]
    return final_hp + 5 * final_mp + 2 * final_attack + 2 * final_defense

def main():
    import sys
    input = sys.stdin.read
    data = list(map(int, input().split()))
    T = data[0]
    results = [calculate_battle_power(*data[i:i+8]) for i in range(1, T*8 + 1, 8)]
    print("\n".join(map(str, results)))

if __name__ == "__main__":
    main()