# Imagesnoop

**Imagesnoop** is a collection of two tools that allow users to collect information about `mkdirat` and `tcp_v4_connect` syscalls.
They were created as a part of the *Exploiting Kubernetes' Image Pull Implementation to Deny Node Availability*, whose code
is available [here](https://github.com/risingfbk/magi).

- [Imagesnoop](#imagesnoop)
  - [Installation](#installation)
  - [TCPConnect](#tcpconnect)
    - [Features](#features)
    - [Usage](#usage)
    - [Arguments](#arguments)
    - [Data structure](#data-structure)
  - [MkDirSnoop](#mkdirsnoop)
    - [Features](#features-1)
    - [Usage](#usage-1)
    - [Arguments](#arguments-1)
    - [Data structure](#data-structure-1)
  - [License](#license)
  - [Contributing](#contributing)
  - [Acknowledgements](#acknowledgements)

## Installation

To install `tcpconnect` and `mkdirssnoop`, make sure BCC version `>0.24.0` is installed and available to your Python installation. To do so,
follow the [relevant installation docs](https://github.com/iovisor/bcc/blob/master/INSTALL.md) in the BCC repository. Then, clone
this repository and run `pip3 install -r requirements.txt` to install the needed Python packages. Finally, run the two tools
using the relevant binary in the repository and the documentation below.

## TCPConnect

TCPConnect is a Python-based tool that traces all TCP `tcp_connect()` calls in your system. It uses eBPF (Berkeley Packet Filter) to monitor these calls and provides a detailed log of the connections.

### Features

- Trace all TCP `connect()` calls
- Filter tracing by specific PID
- Count connects per source IP and destination IP/port
- Save logs to a specified file

### Usage

You can use TCPConnect in the following ways:

- Trace all TCP `connect()` calls:

```bash
./tcpconnect
```

- Only trace a specific PID:

```bash
./tcpconnect -p 181
```

- Change where the log will be saved:

```bash
./tcpconnect -f filename
```

### Arguments

- `-P`, `--pid`: Trace this PID only
- `-f`, `--file`: Log file name (default is "tcp.json")
- `-c`, `--count`: Count connects per source IP and destination IP/port

### Data structure

TCPConnect uses a C structure to store the data of each TCP connection. The structure includes the following fields:

- `ts_us`: Timestamp in microseconds
- `pid`: Process ID
- `tid`: Thread ID
- `uid`: User ID
- `saddr`: Source address
- `daddr`: Destination address
- `lport`: Local port
- `dport`: Destination port
- `comm`: Command name

## MkDirSnoop
§
MkdirSnoop is a Python-based tool that traces all `mkdir()` and `mkdirat()` system calls in your system. It uses the BPF (Berkeley Packet Filter) to monitor these calls and provides a detailed log of the directories created.

### Features

- Trace all `mkdir()` and `mkdirat()` system calls
- Filter tracing by specific PID
- Save logs to a specified file

### Usage

You can use MkdirSnoop in the following ways:

- Trace all `mkdir()` and `mkdirat()` system calls:

```bash
./mkdirsnoop
```

- Only trace a specific PID:

```bash
./mkdirsnoop -p 181
```

- Change where the log will be saved:

```bash
./mkdirsnoop -f filename
```

### Arguments

- `-P`, `--pid`: Trace this PID only
- `-f`, `--file`: Log file name (default is "log.json")

### Data structure

MkdirSnoop uses a C structure to store the data of each directory creation. The structure includes the following fields:

- `ts_us`: Timestamp in microseconds
- `pid`: Process ID
- `tid`: Thread ID
- `uid`: User ID
- `comm`: Command name
- `argv`: Arguments

## License

This software, with respect to the [Linux eBPF licensing](https://docs.kernel.org/bpf/bpf_licensing.html), is
licensed under the GPL License 2.0. See the [LICENSE](LICENSE) file for more details.

## Contributing

All contributions are welcome. If you have any doubts or questions feel free to open an issue or contact the maintainers.

## Acknowledgements

This work was partially supported by project SERICS (PE00000014), MUR National Recovery and Resilience Plan funded by the European Union - NextGenerationEU, and by project FLUIDOS (grant agreement No 101070473), European Union’s Horizon Europe Programme.

The author list is the following:

- [Luis Augusto Dias Knob](https://github.com/luisdknob), Fondazione Bruno Kessler - `l.diasknob@fbk.eu`
- [Matteo Franzil](https://github.com/mfranzil), Fondazione Bruno Kessler - `mfranzil@fbk.eu`
- Domenico Siracusa, Fondazione Bruno Kessler - `dsiracusa@fbk.eu`

If you wish to cite this work for scientific research, do it as follows:

> L. A. D. Knob, M. Franzil, and D. Siracusa, “Exploiting Kubernetes’ Image Pull Implementation to Deny Node Availability.” arXiv. Preprint available: http://arxiv.org/abs/2401.10582. [Accessed: Jan. 23, 2024]
