import Link from 'next/link';
import Seo from '../components/Seo';
import { useRouter } from 'next/router';

interface HomeProps {
	movies: [IMovie];
}

interface IMovie {
	adult: boolean;
	backdrop_path: string;
	genre_ids: [number];
	id: number;
	original_language: string;
	original_title: string;
	overview: string;
	popularity: number;
	poster_path: string;
	release_date: string;
	title: string;
	video: boolean;
	vote_average: number;
	vote_count: number;
}

export default function Home({ movies }: HomeProps) {
	const router = useRouter();
	const onClick = (movie: IMovie) => {
		router.push(`/movies/${movie.original_title}/${movie.id}`);
	};

	return (
		<div className="container">
			<Seo title="Home" />
			{movies?.map((movie) => (
				<div key={movie.id} className="movie" onClick={() => onClick(movie)}>
					<img src={`https://image.tmdb.org/t/p/w500/${movie.poster_path}`} />
					<Link href={`/movies/${movie.original_title}/${movie.id}`}>
						<a>
							<h4>{movie.original_title}</h4>
						</a>
					</Link>
				</div>
			))}
			<style jsx>{`
				.container {
					display: grid;
					grid-template-columns: 1fr 1fr;
					padding: 20px;
					gap: 20px;
				}
				.movie {
					cursor: pointer;
				}
				.movie img {
					max-width: 100%;
					border-radius: 12px;
					transition: transform 0.2s ease-in-out;
					box-shadow: rgba(0, 0, 0, 0.1) 0px 4px 12px;
				}
				.movie:hover img {
					transform: scale(1.05) translateY(-10px);
				}
				.movie h4 {
					font-size: 18px;
					text-align: center;
				}
			`}</style>
		</div>
	);
}

export async function getServerSideProps() {
	const { results: movies } = await (await fetch('http://localhost:3000/api/movies/popular')).json();
	return {
		props: {
			movies
		}
	};
}
