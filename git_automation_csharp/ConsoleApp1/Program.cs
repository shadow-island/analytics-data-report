using System;
using System.Text;
using System.Timers;

namespace gitA
{
    class Program
    {
        static int round = 1;        
        static readonly Timer timer = new System.Timers.Timer();
        static void Main(string[] args)
        {
            // 타이머 생성 및 시작
            timer.Interval = 200; // 단위 milisec
            timer.Elapsed += new ElapsedEventHandler(Timer_Elapsed);
            timer.Start();

            Console.WriteLine("Press Enter to exit");
            Console.ReadLine();
        }

        static void RunCommand(string command)
        {
            System.Diagnostics.ProcessStartInfo proInfo = new System.Diagnostics.ProcessStartInfo();
            System.Diagnostics.Process pro = new System.Diagnostics.Process();
            // 실행할 파일명 입력 -- cmd
            proInfo.FileName = @"cmd";
            // cmd 창 띄우기 -- true(띄우지 않기.) false(띄우기)
            proInfo.CreateNoWindow = true;
            proInfo.UseShellExecute = false;
            // cmd 데이터 받기
            proInfo.RedirectStandardOutput = true;
            // cmd 데이터 보내기
            proInfo.RedirectStandardInput = true;
            // cmd 오류내용 받기
            proInfo.RedirectStandardError = true;
            pro.StartInfo = proInfo;
            pro.Start();
            // CMD 에 보낼 명령어를 입력 합니다.
            pro.StandardInput.Write(command + Environment.NewLine);
            pro.StandardInput.Close();
            // 결과 값을 리턴 받습니다.
            string resultValue = pro.StandardOutput.ReadToEnd();
            pro.WaitForExit();
            pro.Close();
            // 결과 값을 확인 합니다.
            Console.WriteLine(resultValue);
        }

        // 작업쓰레드가 지정된 시간 간격으로 아래 이벤트 핸들러 실행
        static void Timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            timer.Stop();
            Console.WriteLine("Round {0}",round);
            if (round == 5)
            {
                Console.WriteLine("안전 종료");
                return;
            }
            round++;

            // 읽어올 text file 의 경로를 지정 합니다.
            string path = "eukm.log";
            // text file 의 전체 text 를 읽어 옵니다.
            string textValue = System.IO.File.ReadAllText(path);
            int numVal = Int32.Parse(textValue);
            // 읽어온 내용을 화면에 출력 합니다.
            //Console.WriteLine("git file ={0}", numVal);
            numVal++;
            // Text 파일 생성 및 text 를 입력 합니다.
            textValue = Convert.ToString(numVal);
            System.IO.File.WriteAllText(path, textValue, Encoding.Default);
            Console.WriteLine("git file ={0}", textValue);

            RunCommand("git status");
            RunCommand("git commit --all -m csharp_v0");
            RunCommand("git push");

            timer.Start();
        }
    }
}
